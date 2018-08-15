package com.dipendughosh.upbuttonforlowlevelactivitiestoactionbar;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class AActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_a);
    }

    public void openB(View view) {
        startActivity(new Intent(AActivity.this, BActivity.class));
    }
}
