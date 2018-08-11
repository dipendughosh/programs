package com.dipendughosh.extrasdemo;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MathActivity extends AppCompatActivity {


    private TextView txtUserNumber;
    private Button btnDoubleIt;
    private Button btnCancel;
    private int valueToWorkWith;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_math);

        Intent intent = getIntent();
        valueToWorkWith = intent.getIntExtra(MainActivity.EXTRA_NUMBER, 0 );
        txtUserNumber = (TextView) findViewById(R.id.txtUserNumber);
        txtUserNumber.setText("" + valueToWorkWith);

        setupDoubleButton();
        setupCancelButton();
    }


    private void setupDoubleButton() {

        btnDoubleIt = (Button) findViewById(R.id.btnDoubleIt);
        btnDoubleIt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int answer = valueToWorkWith * 2;

                Intent intent = new Intent();
                intent.putExtra(MainActivity.EXTRA_ANSWER, answer);
                setResult(Activity.RESULT_OK, intent);
                finish();
            }
        });
    }

    private void setupCancelButton() {

        btnCancel = (Button) findViewById(R.id.btnCancel);
        btnCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                setResult(Activity.RESULT_CANCELED, intent);
                finish();
            }
        });
    }

}
