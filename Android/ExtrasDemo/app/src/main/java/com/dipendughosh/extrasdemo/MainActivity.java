package com.dipendughosh.extrasdemo;

import android.app.Activity;
import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public static final String EXTRA_NUMBER = "parameter name";
    public static final String EXTRA_ANSWER = "the answer";
    public static final int RESULT_CODE_DO_MATH = 42;
    private Button btnDoMath;
    private EditText etUserDate;
    private TextView txtViewAnswer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setUpDoMathbutton();
    }

    private void setUpDoMathbutton() {
        btnDoMath = (Button)findViewById(R.id.btnDoMath);
        btnDoMath.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                etUserDate = (EditText) findViewById(R.id.etUserDate);
                String userData = etUserDate.getText().toString();
                int userNumber = Integer.parseInt(userData);

                Intent intent = new Intent(MainActivity.this, MathActivity.class);
                intent.putExtra(EXTRA_NUMBER, userNumber);
                //startActivity(intent);
                startActivityForResult(intent, 42);
            }
        });
    }

    //Gets called when the activity we started, finishes
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (resultCode == Activity.RESULT_CANCELED) {
            txtViewAnswer.setText("User Cancled");
            return;
        }

        switch (requestCode) {
            case RESULT_CODE_DO_MATH:
                int answer = data.getIntExtra(EXTRA_ANSWER, 0);
                txtViewAnswer = (TextView) findViewById(R.id.txtViewAnswer);
                txtViewAnswer.setText("" + answer);
        }
    }
}
