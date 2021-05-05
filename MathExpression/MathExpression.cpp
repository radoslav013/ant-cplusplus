#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findResultInBrackets(string& problem);
char extractOperator(string& problem);

int chartoint(char num){

    return num - '0';

}

int extractNumber(string &problem){
    int i = 1, number, startIndex = 0;
    if(problem[0] == '-'){
        i = 2;
        startIndex = 1;
    }
    number = chartoint(problem[startIndex]);
    while(problem[i] >= '0' && problem[i] <= '9'){
        number = number*10 + chartoint(problem[i]);
        i++;
    }

    problem.erase(0, i);

    return startIndex == 0 ? number : number*-1;
    // Equivalent to:
    /*
    if(startIndex == 0){
        return number;
    }else{
        return number*-1;
    }
    */

}

int calculate(int a, char op, int b){

    int result = 0;

    switch(op){

        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;

        default: result = 0;
    }

    return result;

}
/// 5*9+6
int findResult(string& problem){
    int result = findResultInBrackets(problem);
    string tempProblem = to_string(result);
    char op;
    while(problem.length() > 0){

        op = extractOperator(problem);
        if(op == '*' || op == '/'){
            tempProblem += calculate(result, op, findResultInBrackets(problem));
        }else{
            tempProblem += op;
            tempProblem += to_string(findResultInBrackets(problem));
        }
    }
    return findResultInBrackets(tempProblem);
}

char extractOperator(string& problem){
    char op = problem[0];
    problem.erase(0, 1); // remove operator
    return op;
}
// Find result in nested brackets
int findResultInBrackets(string& problem){
    int result;
    char op;
    if(problem[0] == '('){
        problem.erase(0, 1); // remove opening bracket
    }
    result = extractNumber(problem);
    if(problem.length() == 0) {
        return result;
    }
    if(problem[0] == ')'){
        // remove all closing brackets at the end
        while(problem[0] == ')'){
            problem.erase(0, 1); // remove closing bracket
        }
        return result;
    }
    op = extractOperator(problem);
    return calculate(result, op, findResultInBrackets(problem));
}

//TODO: Prioritize by mathematical operations / * + -
int main()
{
    // string problem = "10*4+5";
    string problem = "2+10*5";
    cout << findResult(problem) << endl;
    /*
    -5*-620
    -5*
       -10*
           55+
              5+2
    */


    return 0;
}

/*
Create a string(no spaces; no brackets) = 10+25+325
Valid input formats:
    10
    10+25
    10+25*5
    -10+25*5
    -10+-25*5
    -10+-25*-5
    (-10)*(25*5)
    (-10)*-1*(25*5)

Create a function that extracts the next number(extractNumber(string))
    If the first symbol is minus, start from one position after and multiply the number by -1
	Extracts every symbol until a mathematical operation is met
	Remove the number that we found from the string(the string will be a reference of the original string)
	Returns integer

Create a function that finds the result inside brackets using recursion(findResultInBrackets(string))

Create a function that calculates the result of two numbers and one operation(calculate(int char int))
	Returns integer
*/

