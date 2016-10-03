package com.cryptolab;

import java.security.*;
import java.util.Base64;

/**
 * Created by Svk on 03-10-2016.
 */
public class DigitalSignature {
    public static void main(String[] args) throws NoSuchAlgorithmException, InvalidKeyException, SignatureException {
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(1024);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
        byte[] plaintext = "Hello".getBytes();
        Signature signature = Signature.getInstance("MD5WithRSA");
        signature.initSign(keyPair.getPrivate());
        signature.update(plaintext);
        byte[] sign = signature.sign();
        System.out.println(Base64.getEncoder().encode(sign));
        signature.initVerify(keyPair.getPublic());
        signature.update(plaintext);
        System.out.println(signature.verify(sign));
    }
}
