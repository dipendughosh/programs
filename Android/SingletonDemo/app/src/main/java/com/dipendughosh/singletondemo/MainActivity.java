package com.dipendughosh.singletondemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.dipendughosh.singletondemo.model.BubbleWrap;

import java.io.BufferedReader;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    private Button btnAddMore;
    private Button btnPop;
    private TextView txtBubblesLeft;
    private BubbleWrap bubbleWrap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bubbleWrap = BubbleWrap.getInstance();

        setupAddMoreButton();
        setupPopActivityButton();

    }

    @Override
    protected void onResume() {
        super.onResume();
        updateUI();
    }

    private void setupAddMoreButton() {
        btnAddMore = (Button) findViewById(R.id.btnAddMore);
        btnAddMore.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bubbleWrap.addMoreBubbles();
                updateUI();
            }
        });
    }

    private void setupPopActivityButton() {
        btnPop = (Button) findViewById(R.id.btnPop);
        btnPop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, PopActivity.class);
                startActivity(intent);
            }
        });
    }

    private void updateUI() {
        txtBubblesLeft = (TextView) findViewById(R.id.txtBubblesLeft);
        String msg = String.format(Locale.getDefault(), "%d bubbles left!", bubbleWrap.getNumBubbles());
        txtBubblesLeft.setText(msg);
    }
}
