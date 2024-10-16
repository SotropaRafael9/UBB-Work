using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class EncryptionModule
{


    private static string key;
    

    static EncryptionModule()
    {
        string filePath = "C:\\Users\\Rafael\\Desktop\\UbbWork\\HomeWorks\\SemestruIV\\ISS\\lab1\\key.txt";
        key = File.ReadAllText(filePath);
    }

    public static string Encrypt(string initial_string_for_encryption)
    {
        string result_encryption = "";
        for (int index = 0; index < initial_string_for_encryption.Length; index++)
        {
            // i % key.Length will make the key repeat itself
            result_encryption += (char)(initial_string_for_encryption[index] + key[index % key.Length]);
            // make h+k, e+e, l+y and so on
        }
        return result_encryption;
    }

    public static string Decrypt(string initial_string_for_decryption)
    {
        string result_decryption = "";
        for (int index = 0; index < initial_string_for_decryption.Length; index++)
        {
            result_decryption += (char)(initial_string_for_decryption[index] - key[index % key.Length]);
        }
        return result_decryption;
    }

}

namespace lab1
{
    internal class Program
    {
        //Implement configurable substitution cyphers for strings. The
        //module should be able to encrypt and decrypt.
        
        static void Main(string[] args)
        {        
            string input = "Happy %#@! day 12321";
            string encrypted = EncryptionModule.Encrypt(input);
            string decrypted = EncryptionModule.Decrypt(encrypted);
            Console.WriteLine("Encrypted: " + encrypted);
            Console.WriteLine("Decrypted: " + decrypted);

        }
    }
}

