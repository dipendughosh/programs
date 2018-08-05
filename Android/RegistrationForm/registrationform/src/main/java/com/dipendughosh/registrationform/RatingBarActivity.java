package com.dipendughosh.registrationform;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RatingBar;
import android.widget.TextView;

public class RatingBarActivity extends AppCompatActivity {

    private RatingBar ratingBar;
    private TextView clickValue;
    private TextView submitValue;
    private Button btnSubmit;
    private Button btnBack;
    private Button btnProceed;
    private float rate;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rating_bar);

        ratingBar=(RatingBar)findViewById(R.id.ratingBar);
        clickValue=(TextView)findViewById(R.id.clickValue);
        submitValue=(TextView)findViewById(R.id.submitValue);

        ratingBar.setOnRatingBarChangeListener(new RatingBar.OnRatingBarChangeListener() {
            @Override
            public void onRatingChanged(RatingBar ratingBar, float rating, boolean fromUser) {
                clickValue.setText("Rated Value is : "+rating);
                rate=rating;
            }
        });

        btnSubmit=(Button)findViewById(R.id.btnSubmit);

        btnSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                submitValue.setText("Submitted Value is : "+rate);
            }
        });

        btnBack=(Button)findViewById(R.id.btnBack);

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(RatingBarActivity.this,SeekBarActivity.class);

                startActivity(intent);
            }
        });

        btnProceed=(Button)findViewById(R.id.btnProceed);

        btnProceed.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(RatingBarActivity.this,WebViewActivity.class);

                startActivity(intent);
            }
        });
    }
}
