package com.dipendughosh.testapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "DemoInitialApp";
    private Button btnMagic;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnMagic = (Button) findViewById(R.id.btnMagic);

        btnMagic.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //Log.i("MyApp","This is a magic log message");
                Log.i(TAG,"This is a magic log message");
                Toast.makeText(getApplicationContext(), "Magic", Toast.LENGTH_LONG).show();
            }
        });
    }
}
