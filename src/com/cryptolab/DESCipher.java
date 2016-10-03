package com.cryptolab;

import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.spec.AlgorithmParameterSpec;

public class DESCipher {
    private static Cipher encryptCipher;
    private static Cipher decryptCipher;
    private static final byte[] iv = {11, 22, 33, 44, 99, 88, 77, 66};


    public static void main(String[] args) {

        try {
            //create SecretKey using KeyGenerator
            SecretKey key = KeyGenerator.getInstance("DES").generateKey();
            AlgorithmParameterSpec paramSpec = new IvParameterSpec(iv);

            //get Cipher instance and initiate in encrypt mode
            encryptCipher = Cipher.getInstance("DES/CBC/PKCS5Padding");
            encryptCipher.init(Cipher.ENCRYPT_MODE, key, paramSpec);
            byte[] iptext;
            String plaintext = "Hello";
            iptext = plaintext.getBytes();
            byte[] encrypted = encryptCipher.doFinal(iptext);
            System.out.println(new String(encrypted));
            //get Cipher instance and initiate in decrypt mode
            decryptCipher = Cipher.getInstance("DES/CBC/PKCS5Padding");
            decryptCipher.init(Cipher.DECRYPT_MODE, key, paramSpec);
            byte[] decrypted = decryptCipher.doFinal(encrypted);
            System.out.println(new String(decrypted));
            System.out.println("DONE");
        } catch (NoSuchAlgorithmException |
                NoSuchPaddingException |
                InvalidKeyException |
                InvalidAlgorithmParameterException e) {
            e.printStackTrace();
        } catch (BadPaddingException e) {
            e.printStackTrace();
        } catch (IllegalBlockSizeException e) {
            e.printStackTrace();
        }
    }
}
