package com.example.simplecalc;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.TextView;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;


public class MainActivity extends Activity implements OnClickListener {
	
	EditText etNum;
	TextView tvResult;
	
	Button btn1;
	Button btn2;
	Button btn3;
	Button btn4;
	Button btn5;
	Button btn6;
	Button btn7;
	Button btn8;
	Button btn9;
	Button btn0;
	Button btnadd;
	Button btnsub;
	Button btnprd;
	Button btndiv;
	Button btneq;
	

	 float result ;
	 int n;
	 String operator=" ";
	 
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		etNum = (EditText) findViewById(R.id.etNum);
		tvResult = (TextView) findViewById(R.id.tvResult);
		
		btn1 = (Button) findViewById(R.id.btn1);
		btn2 = (Button) findViewById(R.id.btn2);
		btn3 = (Button) findViewById(R.id.btn3);
		btn4 = (Button) findViewById(R.id.btn4);
		btn5 = (Button) findViewById(R.id.btn5);
		btn6 = (Button) findViewById(R.id.btn6);
		btn7 = (Button) findViewById(R.id.btn7);
		btn8 = (Button) findViewById(R.id.btn8);
		btn9 = (Button) findViewById(R.id.btn9);
		btn0 = (Button) findViewById(R.id.btn0);
		btnadd = (Button) findViewById(R.id.btnadd);
		btnsub = (Button) findViewById(R.id.btnsub);
		btnprd = (Button) findViewById(R.id.btnprd);
		btndiv = (Button) findViewById(R.id.btndiv);
		btneq = (Button) findViewById(R.id.btneq);
		
		 btn1.setOnClickListener(this);
		 btn2.setOnClickListener(this);
		 btn3.setOnClickListener(this);
		 btn4.setOnClickListener(this);
		 btn5.setOnClickListener(this);
		 btn6.setOnClickListener(this);
		 btn7.setOnClickListener(this);
		 btn8.setOnClickListener(this);
		 btn9.setOnClickListener(this);
		 btn0.setOnClickListener(this);
		 btnadd.setOnClickListener(this);
		 btnsub.setOnClickListener(this);
		 btnprd.setOnClickListener(this);
		 btndiv.setOnClickListener(this);
		 btneq.setOnClickListener(this);
		 
		}

	@Override
	public void onClick(View v) {
		
		 switch(v.getId()){
	     case R.id.btn1:
	    	 etNum.append("1");
	    	 break;
	     case R.id.btn2:
	    	 etNum.append("2");
	    	 break;
	     case R.id.btn3:
	    	 etNum.append("3");
	    	 break;
	     case R.id.btn4:
	    	 etNum.append("4");
	    	 break;
	     case R.id.btn5:
	    	 etNum.append("5");
	    	 break;
	     case R.id.btn6:
	    	 etNum.append("6");
	    	 break;
	     case R.id.btn7:
	    	 etNum.append("7");
	    	 break;
	     case R.id.btn8:
	    	 etNum.append("8");
	    	 break;
	     case R.id.btn9:
	    	 etNum.append("9");
	    	 break;
	     case R.id.btn0:
	    	 etNum.append("0");
	    	 break;
	    	
	     case R.id.btnadd:
	    	 operator="+";
	    	 etNum.append(" + ");
	    	 break;
	     case R.id.btnsub:
	    	 operator="-";
	    	 etNum.append(" - ");
	    	 break;
	     case R.id.btnprd:
	    	 operator="*";
	    	 etNum.append(" * ");
	         break;
	     case R.id.btndiv:
	    	 operator="/";
	    	 etNum.append(" / ");
	    	 break;
	    	 
	     case R.id.btneq:
	    	 String inputStr = etNum.getText().toString();
       	     String [] r=inputStr.split("\\s+");
       	  
       	     Float n1=Float.parseFloat(r[0]);
	       	 Float n2=Float.parseFloat(r[2]);
	       
		   if (operator.equals("+")) {
           result = n1+n2;
        } else if (operator.equals("-")) {
           result = n1-n2;
        } else if (operator.equals("*")) {
           result = n1*n2;
        } else if (operator.equals("/")) {
           result = n1/n2;
        } 
		   	tvResult.setText(String.valueOf(result));
		   	break;
       	 }
	}

}