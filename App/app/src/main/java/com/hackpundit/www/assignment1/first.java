package com.hackpundit.www.assignment1;



import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.util.Random;

public class first extends AppCompatActivity {






//    Button button0 , button1 , button2 , button3 , button4 , button5 , button6 ,
//            button7 , button8 , button9 , buttonAdd , buttonSub , buttonDivision ,
//            buttonMul , button10 , buttonC , buttonEqual, buttonNext ;
//
//    EditText edt1, question ;
//
//    String[] QuestionsArray={"OK, What is 4+5?","what is 5+8","What is 8*3"};
//    float[] answersArray={9,13,24};
//    float answer;
//    boolean repeat=false;
////    boolean answeredCorrectly;
//
//    int qac=0; //questions array counter
//    int aac=0; //answers array counter
//    float mValueOne , mValueTwo, retry ;
//    boolean mAddition , mSubtract ,mMultiplication ,mDivision, first, correct ;
//    int fc = 1, count = 0;
//
//
    public Button start;
    public void begin()
    {
        start=(Button)findViewById(R.id.start);
        start.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v)
            {

                Intent start=new Intent(com.hackpundit.www.assignment1.first.this,newMain.class);
                startActivity(start);
            }
        });
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first);

        begin();


//
//        button0 = (Button) findViewById(R.id.button0);
//        button1 = (Button) findViewById(R.id.button1);
//        button2 = (Button) findViewById(R.id.button2);
//        button3 = (Button) findViewById(R.id.button3);
//        button4 = (Button) findViewById(R.id.button4);
//        button5 = (Button) findViewById(R.id.button5);
//        button6 = (Button) findViewById(R.id.button6);
//        button7 = (Button) findViewById(R.id.button7);
//        button8 = (Button) findViewById(R.id.button8);
//        button9 = (Button) findViewById(R.id.button9);
//        button10 = (Button) findViewById(R.id.button10);
//       /* buttonAdd = (Button) findViewById(R.id.buttonadd);
//        buttonSub = (Button) findViewById(R.id.buttonsub);
//        buttonMul = (Button) findViewById(R.id.buttonmul);
//        buttonDivision = (Button) findViewById(R.id.buttondiv);*/
//        buttonC = (Button) findViewById(R.id.buttonC);
//        buttonEqual = (Button) findViewById(R.id.buttoneql);
//        buttonNext = (Button) findViewById(R.id.buttonNext);
//        edt1 = (EditText) findViewById(R.id.edt1);
//        question = (EditText) findViewById(R.id.Question);
//
//        but1.setEnabled(false); //set this initially to false so that you cannot click it
//
//        button1.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"1");
//            }
//        });
//
//        button2.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"2");
//            }
//        });
//
//        button3.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"3");
//            }
//        });
//
//        button4.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"4");
//            }
//        });
//
//        button5.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"5");
//            }
//        });
//
//        button6.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"6");
//            }
//        });
//
//        button7.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"7");
//            }
//        });
//
//        button8.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"8");
//            }
//        });
//
//        button9.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"9");
//            }
//        });
//
//        button0.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+"0");
//            }
//        });
//
//        question.setText("Hi, I am a super smart AI."); // show this text at beginning
//        buttonNext.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                if (fc == 1) {
//                    question.setText("I want you to answer my math questions");
//                    fc = 2;
//                }
//                else if(count < 3)
//                {
//                    int num1, num2, num3;
//                    String[] OperatorArray={"+","-"};
//                    Random ran = new Random();
//                    num1 = ran.nextInt(100);
//                    num2 = ran.nextInt(100);
//                    num3 = ran.nextInt(2);
//                    if(num3 == 0) {
//                        question.setText("What is " + num1 + OperatorArray[num3] + num2 + "?");
//                        buttonNext.setEnabled(false); //so you can't click on it until after you press equals
//                        answer = num1 + num2;
//                    }
//                    else{
//                        question.setText("What is " + num1 + OperatorArray[num3] + num2 + "?");
//                        buttonNext.setEnabled(false); //so you can't click on it until after you press equals
//                        answer = num1 - num2;
//                    }
//                    //question.setText(QuestionsArray[qac]);
//
//
//
//                }
//                else
//                {
//                    question.setText("you have completed all the questions! great job");
//                    but1.setEnabled(true);
//                    question.append("press calc");
//                }
//            }
//        });
//
///*
//        int num1, num2;
//        Random ran = new Random();
//        num1 = ran.nextInt(100);
//        num2 = ran.nextInt(100);
//        question.setText(num1+" + "+ num2);
//*/
//
////        buttonAdd.setOnClickListener(new View.OnClickListener() {
////            @Override
////            public void onClick(View v) {
////
////                if (edt1 == null){
////                    edt1.setText("");
////
////                }else {
////                    mValueOne = Float.parseFloat(edt1.getText() + "");
////                    mAddition = true;
////                    edt1.setText(null);
////                }
////            }
////        });
////
////        buttonSub.setOnClickListener(new View.OnClickListener() {
////            @Override
////            public void onClick(View v) {
////                mValueOne = Float.parseFloat(edt1.getText() + "");
////                mSubtract = true ;
////                edt1.setText(null);
////            }
////        });
////
////        buttonMul.setOnClickListener(new View.OnClickListener() {
////            @Override
////            public void onClick(View v) {
////                mValueOne = Float.parseFloat(edt1.getText() + "");
////                mMultiplication = true ;
////                edt1.setText(null);
////            }
////        });
////
////        buttonDivision.setOnClickListener(new View.OnClickListener() {
////            @Override
////            public void onClick(View v) {
////                mValueOne = Float.parseFloat(edt1.getText()+"");
////                mDivision = true;
////                edt1.setText(null);
////            }
////        });
////      Enter should redefine.
//        buttonEqual.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                mValueTwo = Float.parseFloat(edt1.getText() + "");
//
//                if(answer==mValueTwo)
//                {
//                    question.setText("Correct! press next button for next question");
//                    buttonNext.setEnabled(true); //now you can click the next button!
//                    edt1.setText("");
//                    aac++;
//                    qac++;
//                    count++;
//                }
//                else
//                {
//                    question.setText("That's Incorrect! Press Next for another question");
//                    repeat=true;
//                    buttonNext.setEnabled(true);
//                    edt1.setText("");
//                   // question.append(QuestionsArray[qac]);
//                }
////                if(mValueTwo == answer){
////                    count++;
////                }
////                else{
////                    //delete app
////                }
////
////                if(count == 1){
////                    question.setText("Correct! What is 2*2=");
////                    answer = 4;
////                }
////                else if(count == 2){
////                    question.setText("Correct! What is 4/2=");
////                    answer = 2;
////                }
//
//                /*if (mAddition == true){
//
//                    edt1.setText(mValueOne + mValueTwo +"");
//                    mAddition=false;
//                }
//
//
//                if (mSubtract == true){
//                    edt1.setText(mValueOne - mValueTwo+"");
//                    mSubtract=false;
//                }
//
//                if (mMultiplication == true){
//                    edt1.setText(mValueOne * mValueTwo+"");
//                    mMultiplication=false;
//                }
//
//                if (mDivision == true){
//                    edt1.setText(mValueOne / mValueTwo+"");
//                    mDivision=false;
//                }*/
//            }
//        });
//
//        buttonC.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText("");
//            }
//        });
//
//        button10.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                edt1.setText(edt1.getText()+".");
//            }
//        });
//    }



}}