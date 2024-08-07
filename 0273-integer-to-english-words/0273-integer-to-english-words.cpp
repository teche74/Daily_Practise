class Solution {
public:
    string numberToWords(int num) {
        string units[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
        string teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

            if (num == 0) {
                return "Zero";
            }
                if (num < 10) {
                return units[num];
            }
            else if (num < 20) {
                return teens[num - 10];
            }
            else if (num < 100) {
                string result = tens[num / 10];
                if (num % 10 != 0) {
                    result += " " + units[num % 10];
                }
                return result;
            }
            else if (num < 1000) {
                string result = units[num / 100] + " Hundred";
                if (num % 100 != 0) {
                    result += " " + numberToWords(num % 100);
                }
                return result;
            }
            else if (num < 1000000) {
                string result = numberToWords(num / 1000) + " Thousand";
                if (num % 1000 != 0) {
                    result += " " + numberToWords(num % 1000);
                }
                return result;
            }
            else if (num < 1000000000) {
                string result = numberToWords(num / 1000000) + " Million";
                if (num % 1000000 != 0) {
                    result += " " + numberToWords(num % 1000000);
                }
                return result;
            }
            else if (num <= 2147483647) { // 2^31 - 1
                string result = numberToWords(num / 1000000000) + " Billion";
                if (num % 1000000000 != 0) {
                    result += " " + numberToWords(num % 1000000000);
                }
                return result;
            }
        return "Number too large";
    }
};