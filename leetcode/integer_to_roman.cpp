class Solution {
public:
    string intToRoman(int num) {
        string result;
        while(num){
            switch(num)
            {
                case 1 ... 3: result += 'I';
                    num--;
                    break;
                case 4: result += "IV";
                    num -= 4;
                    break;
                case 5 ... 8: result += 'V';
                    num -= 5;
                    break;
                case 9: result += "IX";
                    num -= 9;
                    break;
                case 10 ... 39: result += 'X';
                    num -= 10;
                    break;
                case 40 ... 49: result += "XL";
                    num -= 40;
                    break;
                case 50 ... 89: result += 'L';
                    num -= 50;
                    break;
                case 90 ... 99: result += "XC";
                    num -= 90;
                    break;
                case 100 ... 399: result += 'C';
                    num -= 100;
                    break;
                case 400 ... 499: result += "CD";
                    num -= 400;
                    break;
                case 500 ... 899: result += 'D';
                    num -= 500;
                    break;
                case 900 ... 999: result += "CM";
                    num -= 900;
                    break;
                default : result += 'M';
                    num -= 1000;
            }
        }
        return result;
    }
};

//	Runtime: 8 ms, faster than 90.91% of C++ online submissions for Integer to Roman.
//	Memory Usage: 6 MB, less than 69.40% of C++ online submissions for Integer to Roman.