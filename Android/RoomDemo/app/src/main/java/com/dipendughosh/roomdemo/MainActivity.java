package com.dipendughosh.roomdemo;

import android.arch.persistence.room.Room;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    public static FragmentManager fragmentManager;
    public static MyaAppDatabase myaAppDatabase;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fragmentManager = getSupportFragmentManager();
        myaAppDatabase = Room.databaseBuilder(getApplicationContext(), MyaAppDatabase.class, "userdb").allowMainThreadQueries().build();

        if (findViewById(R.id.fragment_container) != null) {

            if (savedInstanceState != null) {
                return;
            }

            HomeFragment homeFragment = new HomeFragment();
            fragmentManager.beginTransaction().add(R.id.fragment_container, homeFragment).commit();

        }
    }
}
