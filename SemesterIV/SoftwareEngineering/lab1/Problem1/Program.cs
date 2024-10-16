using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;




namespace Problem1
{
    internal class Program
    {
        public static int length_of_longest_substring(string string_that_is_given)
        {

            int length_of_the_string = string_that_is_given.Length;
            int storing_elements_without_reapeating = 0;
            Dictionary<char, int> map = new Dictionary<char, int>(); //last index

            for(int index_to_parse_the_string =0; index_to_parse_the_string < length_of_the_string;index_to_parse_the_string++)
            {
                if (map.ContainsKey(string_that_is_given[index_to_parse_the_string]))
                {
                    // wea assure to alaways have the maximum length of the substring
                    storing_elements_without_reapeating = Math.Max(storing_elements_without_reapeating, map.Count);
                    index_to_parse_the_string = map[string_that_is_given[index_to_parse_the_string]];//go to next index
                    map.Clear();// to start over
                }
                else
                {
                    map.Add(string_that_is_given[index_to_parse_the_string], index_to_parse_the_string);
                }

            }
            // update with the last substring
            storing_elements_without_reapeating = Math.Max(storing_elements_without_reapeating, map.Count);

            return storing_elements_without_reapeating;

        }
        static void Main(string[] args)
        {
            // write a program that finds the length of the longest substring without repeating characters
            //ex input: "abcabcbb" output: 3
           
            string string_that_is_given = "abcabcbb";
            int result = length_of_longest_substring(string_that_is_given);
            Console.WriteLine(result);
          

        }
    }
}
