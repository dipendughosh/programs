package com.dipendughosh.autocompletetextviewdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;

public class MainActivity extends AppCompatActivity {

    private AutoCompleteTextView autoCompleteTextView;
    String[] countries = {
            "Afganisthan",
            "Albeania",
            "Algeria",
            "Andorra",
            "Angola",
            "Antigua",
            "Argentina",
            "Armenia",
            "Australia",
            "Austria",
            "Azerbaijan",
    };
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        autoCompleteTextView = (AutoCompleteTextView) findViewById(R.id.autoCompleteTextView);

        ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.select_dialog_item, countries);

        autoCompleteTextView.setThreshold(1);
        autoCompleteTextView.setAdapter(adapter);
    }
}
