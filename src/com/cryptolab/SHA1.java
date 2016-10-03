package com.cryptolab;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Created by Svk on 03-10-2016.
 */
public class SHA1 {
    public static String getSHA1(String plaintext) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA1");
        byte[] encryptedbyte = md.digest(plaintext.getBytes());
        BigInteger number = new BigInteger(1,encryptedbyte);
        String hashtext = number.toString();
        if(hashtext.length()<0){
            hashtext = "0"+hashtext;
        }
        return hashtext;
    }
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String plaintext = br.readLine();
        try {
            System.out.println(getSHA1(plaintext));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
