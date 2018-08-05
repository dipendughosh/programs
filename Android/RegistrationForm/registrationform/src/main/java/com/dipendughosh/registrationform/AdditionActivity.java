package com.dipendughosh.registrationform;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class AdditionActivity extends AppCompatActivity {

    private EditText et1,et2;
    private Button btnAdd;
    private TextView tvAns;
    private Button btnBack;
    private Button btnProceed;

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

        btnBack=(Button)findViewById(R.id.btnBack);

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(AdditionActivity.this,MainActivity.class);

                startActivity(intent);
            }
        });

        btnProceed=(Button)findViewById(R.id.btnProceed);

        btnProceed.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(AdditionActivity.this,SignUpActivity.class);

                startActivity(intent);
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
