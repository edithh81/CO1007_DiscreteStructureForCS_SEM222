#include "test.h"
int main(){
     /* HOW TO RUN THE PROGRAM
    g++ -g -o main main.cpp test.cpp -I . -std=c++11 (file: compile.sh)
    .\main (run.sh)
    */
    // VARIABLES
    string postfix, prefix, result, result1,logicPostfix, logicPrefix, logicResult, logicResult1;
    //

    // INFIX TO POSTFIX OR PREFIX
    cout <<"INFIX TO POSTFIX OR PREFIX" <<endl;
    string infix[2]={"123-456+789","3-5+6*10"};
    for (int i=0; i<2;i++){
        postfix=Infix2Postfix(infix[i]);
        prefix=Infix2Prefix(infix[i]);
        if(postfix=="UNDEFINED ERROR"||postfix=="SYNTAX ERROR"||postfix=="DIVIDED BY 0 ERROR"){
            result=postfix;
            result1=result;
        }
        else{
            result=PostfixPrefixCalculator(postfix);
            result1=PostfixPrefixCalculator(prefix);
        }
        cout << "Testcase" << i+1<<":" << endl;
        cout << "Infix: " << infix[i] << endl
        <<"Postfix: "<< postfix << endl
        <<"Prefix: "<<prefix<<endl
        <<"PostfixCalculator: " <<result <<endl
        <<"PrefixCalculator: "<<result1 <<endl
        << string(50, '-') << endl;
    }

    // LOGICINFIX TO LOGICPOSTFIX OR LOGICPREFIX
    cout <<"LOGICINFIX TO LOGICPOSTFIX OR LOGICPREFIX"<<endl;
    string logicInfix[2]={"~t->(w&z)|p&q|y","p<->q->r"};
    string varlue[2]={"t w z p q y 1 1 1 1 0 0","p q r 1 0 1"};
    for (int i=0; i<2;i++){
        logicPostfix=LogicInfix2Postfix(logicInfix[i]);
        logicPrefix=LogicInfix2Prefix(logicInfix[i]);
        if(logicPostfix=="SYNTAX ERROR"){
            logicResult=logicPostfix;
            logicResult1=logicResult;
        }
        else{
            logicResult=LogicPostfixPrefixCalculator(logicPostfix,varlue[i]);
            logicResult1=LogicPostfixPrefixCalculator(logicPrefix,varlue[i]);
        }
        cout << "Testcase" << i+1<<":" << endl;
        cout << "LogicInfix: " << logicInfix[i] << endl
        <<"LogicPostfix: "<< logicPostfix << endl
        <<"LogicPrefix: "<<logicPrefix<<endl
        <<"LogicPostfixCalculator: " <<logicResult <<endl
        <<"LogicPrefixCalculator: "<<logicResult1 <<endl
        << string(50, '-') << endl;
    }
}