package com.dipendughosh.singletondemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.dipendughosh.singletondemo.model.BubbleWrap;

import java.util.Locale;

public class PopActivity extends AppCompatActivity {

    private TextView txtlblBubbleDisplay;
    private BubbleWrap bubbleWrap;
    private Button btnPop;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pop);

        bubbleWrap = BubbleWrap.getInstance();

        setupPopButton();
        updateUI();
    }

    private void setupPopButton() {
        btnPop = (Button) findViewById(R.id.btnPop);
        btnPop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bubbleWrap.popBubble();
                Toast.makeText(PopActivity.this, "POP!", Toast.LENGTH_SHORT).show();
                updateUI();
            }
        });
    }

    private void updateUI() {
        txtlblBubbleDisplay = (TextView) findViewById(R.id.txtlblBubbleDisplay);
        String msg = String.format(Locale.getDefault(), "%d bubbles left!", bubbleWrap.getNumBubbles());
        txtlblBubbleDisplay.setText(msg);
    }
}
