package com.dipendughosh.fragmentdemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;

public class MainActivity extends AppCompatActivity {

    private Button btnFragment1;
    private Button btnFragment2;
    private Button btnXmlFragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnFragment1 = (Button) findViewById(R.id.btnFragment1);
        btnFragment2 = (Button) findViewById(R.id.btnFragment2);
        btnXmlFragment = (Button) findViewById(R.id.btnXmlFragment);
    }

    public void changeFragment(View view) {
        Fragment fragment = null;

        if ( view == btnFragment1 ) {
            fragment = new FragmentOne();
        }
        if ( view == btnFragment2) {
            fragment = new FragmentTwo();
        }

        if (fragment != null) {
            FragmentManager fm = getFragmentManager();
            FragmentTransaction ft = fm.beginTransaction();
            ft.replace(R.id.fragmentPlace, fragment);
            ft.commit();
        }
    }

    public void xmlFragment(View view) {
        startActivity(new Intent(MainActivity.this, XmlFragmentActivity.class));
    }
}
