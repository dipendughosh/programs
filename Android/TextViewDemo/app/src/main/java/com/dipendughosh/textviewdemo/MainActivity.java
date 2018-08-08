package com.dipendughosh.textviewdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private Button btnCountUp;
    private TextView txtCountUp;
    private int count = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtCountUp = (TextView) findViewById(R.id.txtCountUp);
        btnCountUp = (Button) findViewById(R.id.btnCountUp);

        btnCountUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                count ++;
                String message = getString(R.string.current_count);
                txtCountUp.setText(message + " " + count);

            }
        });
    }
}
