package com.dipendughosh.alertdialogdemo;

import android.support.v4.app.FragmentManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button btnSetMsg;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupSetMessage();
    }

    private void setupSetMessage() {

        btnSetMsg = (Button) findViewById(R.id.btnSetMsg);
        btnSetMsg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FragmentManager manager = getSupportFragmentManager();
                MessageFragment dialog = new MessageFragment();
                dialog.show(manager, "MessageDialog");

                Log.i("TAG", "Just showed the dialog");
            }
        });
    }
}
