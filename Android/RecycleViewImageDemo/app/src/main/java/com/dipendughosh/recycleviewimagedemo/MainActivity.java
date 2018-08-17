package com.dipendughosh.recycleviewimagedemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.GridLayoutManager;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private int[] images = {R.drawable.ic_menu_1,
                            R.drawable.ic_menu_2,
                            R.drawable.ic_menu_3,
                            R.drawable.ic_menu_4,
                            R.drawable.ic_menu_5,
                            R.drawable.ic_menu_6,
                            R.drawable.ic_menu_7,
                            R.drawable.ic_menu_8,
                            R.drawable.ic_menu_9,
                            R.drawable.ic_menu_10};
    private RecyclerView.LayoutManager layoutManager;
    private RecylerAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.recylerview);
        layoutManager = new GridLayoutManager(this, 2);
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(layoutManager);
        adapter = new RecylerAdapter(images);
        recyclerView.setAdapter(adapter);

    }
}
