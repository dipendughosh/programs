package com.dipendughosh.switchactivitydemo;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class ThirdActivity extends AppCompatActivity {


    public static final String MESSAGE_CODE = "com.dipendughosh.switchactivitydemo.ThirdActivity data message";
    private Button btnEndSecond;
    private EditText edtTxtMessage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);

        setupEndButton();
    }

    private void setupEndButton() {
        btnEndSecond = (Button) findViewById(R.id.btnEndThird);
        btnEndSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(ThirdActivity.this, "Clicked, end second", Toast.LENGTH_SHORT).show();
                //Extract data from the UI
                edtTxtMessage = (EditText) findViewById(R.id.edtTxtMessage);
                String message = edtTxtMessage.getText().toString();
                //Pass data back
                Intent intent = new Intent();
                intent.putExtra(MESSAGE_CODE, message);
                setResult(Activity.RESULT_OK, intent);
                finish();
                //Common Bug: intent is to launch MainActivity
                //Intent intent = new Intent(SecondActivity.this, MainActivity.class);
                //startActivity(intent);
            }
        });
    }

    public static Intent makeIntent(Context context) {
        Intent intent = new Intent(context, ThirdActivity.class);
        return intent;

    }

    public static String getResultMessage(Intent intent) {
        return intent.getStringExtra(MESSAGE_CODE);
    }
}
