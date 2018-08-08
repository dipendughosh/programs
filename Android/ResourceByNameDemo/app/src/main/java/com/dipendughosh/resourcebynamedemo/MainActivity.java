package com.dipendughosh.resourcebynamedemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    private Button btnNextImage;
    private ImageView imageView;
    private int currImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupNextImage();
    }

    private void setupNextImage() {

        btnNextImage = (Button) findViewById(R.id.btnNextImage);
        currImage = 1;

        btnNextImage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                currImage++;
                if(currImage > 4) {
                    currImage = 1;
                }

                UpdateUI();
            }
        });
    }

    private void UpdateUI() {
        String filename = "b" + currImage;
        int id = getResources().getIdentifier(filename, "drawable", MainActivity.this.getPackageName());

        imageView = (ImageView) findViewById(R.id.imageView);
        //imageView.setImageResource(R.drawable.b3);
        imageView.setImageResource(id);
    }
}
