package com.dipendughosh.demoasync;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MenuInflater;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.sql.SQLOutput;

public class MainActivity extends AppCompatActivity {

    private EditText num1;
    private EditText num2;
    private Button btnMult;
    private String result;
    String strUrl="http://www.telusko.com/addition.htm?t1=3&t2=6";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        num1=(EditText)findViewById(R.id.num1);
        num2=(EditText)findViewById(R.id.num2);
        btnMult=(Button)findViewById(R.id.btnMult);

        btnMult.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int i=Integer.parseInt(num1.getText().toString());
                int j=Integer.parseInt(num2.getText().toString());

                strUrl="https://www.google.com";

                new MultiplyTask().execute(strUrl);
            }
        });
    }

    public class MultiplyTask extends AsyncTask<String ,String ,String >{

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
        }

        @Override
        protected void onPostExecute(String s) {
            //super.onPostExecute(s);
            Toast.makeText(MainActivity.this,"The output is : "+s,Toast.LENGTH_LONG).show();
        }

        @Override
        protected String doInBackground(String... params) {
            try{
                URL url=new URL(params[0]);
                HttpURLConnection con=(HttpURLConnection)url.openConnection();
                con.setRequestMethod("GET");
                con.connect();

                BufferedReader bf=new BufferedReader(new InputStreamReader(con.getInputStream()));
                String value=bf.readLine();
                System.out.println("result is : "+value);
                result=value;
            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return result;
        }
    }
}
