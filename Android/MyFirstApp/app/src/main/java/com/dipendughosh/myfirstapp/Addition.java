package com.dipendughosh.myfirstapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class Addition extends AppCompatActivity {

    EditText et1,et2;
    Button btnAdd;
    TextView tvAns;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_addition);

        et1 = (EditText)findViewById(R.id.et1);
        et2 = (EditText)findViewById(R.id.et2);
        btnAdd = (Button)findViewById(R.id.btnAdd);
        tvAns = (TextView)findViewById(R.id.tvAns);

        btnAdd.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                int i = Integer.parseInt(et1.getText().toString());
                int j = Integer.parseInt(et2.getText().toString());
                int ans;
                ans = i + j;
                tvAns.setText("Ans is : " + ans);
            }
        });
    }

/*    public void add(View v) {
        int et1 = Integer.parseInt(this.et1.getText().toString());
        int et2 = Integer.parseInt(this.et2.getText().toString());
        int ans;
        ans = et1 + et2;
        this.tvAns.setText("Ans is : " + ans);
    }*/
}
