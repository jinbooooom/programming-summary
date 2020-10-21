package hash;

import java.io.*;
import java.nio.file.*;
import java.security.*;

/**
 * This program computes the message digest of a file.
 * @version 1.21 2018-04-10
 * @author Cay Horstmann
 */
public class Digest
{
   /** 
    * @param args args[0] is the filename, args[1] is optionally the algorithm 
    * (SHA-1, SHA-256, or MD5)
    */
   public static void main(String[] args) throws IOException, GeneralSecurityException
   {
      String algname = args.length >= 2 ? args[1] : "SHA-1";                     
      MessageDigest alg = MessageDigest.getInstance(algname);
      byte[] input = Files.readAllBytes(Paths.get(args[0]));
      byte[] hash = alg.digest(input);
      for (int i = 0; i < hash.length; i++)
         System.out.printf("%02X ", hash[i] & 0xFF);
      System.out.println();
   }
}
