import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import javax.xml.bind.DatatypeConverter;

public class MyCipher {
	
  public static void main(String[] args) throws Exception  {
		 long startTime = System.nanoTime();

	     // call function
	     doMain();

	     long endTime = System.nanoTime();
	     long timeDifference = endTime - startTime;
	     System.out.println(timeDifference);
	     
	}
  
  public static void doMain() throws Exception {
	  /*key */
     DataInputStream dis =
		    new DataInputStream (
		    	 new FileInputStream ("/Users/Skelix/Desktop/labs/key.txt"));

		 byte[] datainBytes = new byte[dis.available()];
		 dis.readFully(datainBytes);
		 dis.close();

		 String key = new String(datainBytes, 0, datainBytes.length);

	/*  original text */
		 DataInputStream pdis =
				    new DataInputStream (
				    	 new FileInputStream ("/Users/Skelix/Desktop/labs/original50mb.txt"));

				 byte[] pBytes = new byte[pdis.available()];
				 pdis.readFully(pBytes);
				 pdis.close();

				 String plaintext = new String(pBytes, 0, pBytes.length);
    
  	
  	String crp = encrypt(plaintext, key);
  	String dec = decrypt(crp, key);
  	
   /*Printing encryption to text file*/
  
  	try(  PrintWriter out = new PrintWriter( "/Users/Skelix/Desktop/labs/encrypted1.txt" )  ){
  	    out.println( crp );
  	      
  	}
  	/*Printing decryption to text file*/
  	
  	
  
  	try(  PrintWriter out = new PrintWriter( "/Users/Skelix/Desktop/labs/decrypted1.txt" )  ){
  	    out.println( dec );
  	      
  	}
  }
  

  
  
  private static final String ALGORITHM = "AES/CBC/PKCS5Padding";
private static final String CODIFICACION = "UTF-8";

public static String encrypt(String plaintext, String key)throws NoSuchAlgorithmException, NoSuchPaddingException,InvalidKeyException, IllegalBlockSizeException,BadPaddingException, IOException{
	byte[] raw = DatatypeConverter.parseHexBinary(key);
	SecretKeySpec skeySpec = new SecretKeySpec(raw, "AES");
	Cipher cipher = Cipher.getInstance(ALGORITHM);
	cipher.init(Cipher.ENCRYPT_MODE, skeySpec);
	byte[] cipherText = cipher.doFinal(plaintext.getBytes(CODIFICACION));
	byte[] iv = cipher.getIV();
	ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
	outputStream.write(iv);
	outputStream.write(cipherText);
	byte[] finalData = outputStream.toByteArray();
	String encodedFinalData = DatatypeConverter.printBase64Binary(finalData);
	return encodedFinalData;
}

public static String decrypt(String encodedInitialData, String key)throws InvalidKeyException, IllegalBlockSizeException,BadPaddingException, UnsupportedEncodingException,NoSuchAlgorithmException, NoSuchPaddingException,InvalidAlgorithmParameterException{
	byte[] encryptedData = DatatypeConverter.parseBase64Binary(encodedInitialData);
	byte[] raw = DatatypeConverter.parseHexBinary(key);
	SecretKeySpec skeySpec = new SecretKeySpec(raw, "AES");
	Cipher cipher = Cipher.getInstance(ALGORITHM);
	byte[] iv = Arrays.copyOfRange(encryptedData, 0, 16);
	byte[] cipherText = Arrays.copyOfRange(encryptedData, 16, encryptedData.length);
	IvParameterSpec iv_specs = new IvParameterSpec(iv);
	cipher.init(Cipher.DECRYPT_MODE, skeySpec, iv_specs);
	byte[] plainTextBytes = cipher.doFinal(cipherText);
	String plainText = new String(plainTextBytes);
	return plainText;
	}
}
 

