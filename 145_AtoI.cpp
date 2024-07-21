int createAtoi(string s) {
    // Write your code here.
    bool foundFirstCharter = false;
    bool isNegative = false;
    bool gotSign = false;
    bool isOutOfBound = false;
    int result = 0;
    for(int i = 0;i < s.size(); i++){

        if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')) break;

        if(s[i] >= '0' and s[i] <= '9'){
            foundFirstCharter = true;
            result = result * 10 + int(s[i] - '0');
            if(result < 0) {
                isOutOfBound = true;
                break;
            }
        }


        if(!foundFirstCharter){
            if(s[i] == ' ') continue;
            if(gotSign) break;
            if(s[i] == '-'){
                isNegative = true;
                gotSign = true;
            }else if(s[i] == '+'){
                gotSign = true;
            }
        }

    }

    if(isOutOfBound){
        if(isNegative) result = INT_MIN;
        else result = INT_MAX;
    }else{
        result = isNegative ? -result : result;
    }

    return result;
}