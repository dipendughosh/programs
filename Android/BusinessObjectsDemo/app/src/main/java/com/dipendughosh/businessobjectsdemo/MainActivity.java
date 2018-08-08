package com.dipendughosh.businessobjectsdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private PetRock rocky = new PetRock();
    private Button btnHappy;
    private Button btnSad;
    private TextView txtRockyFeeling;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupEmotionButton(R.id.btnHappy, PetRock.Emotion.HAPPY);
        setupEmotionButton(R.id.btnSad, PetRock.Emotion.SAD);
        //setupHappyButton();
        //setupSadButton();
        updateUI();
    }

    private void setupEmotionButton(int buttonId, final PetRock.Emotion newEmotion) {
        btnHappy = (Button) findViewById(buttonId);

        btnHappy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                rocky.setCurrentEmotion(newEmotion);
                updateUI();
            }
        });
    }

/*    private void setupHappyButton() {
        btnHappy = (Button) findViewById(R.id.btnHappy);

        btnHappy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                rocky.setCurrentEmotion(PetRock.Emotion.HAPPY);
                updateUI();
            }
        });
    }

    private void setupSadButton() {
        btnSad = (Button) findViewById(R.id.btnSad);

        btnSad.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                rocky.setCurrentEmotion(PetRock.Emotion.SAD);
                updateUI();
            }
        });
    }
*/

    private void updateUI() {
        txtRockyFeeling = (TextView) findViewById(R.id.txtRockyFeeling);
        String feeling = rocky.toString();
        txtRockyFeeling.setText(feeling);
    }

}
