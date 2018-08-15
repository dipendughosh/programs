package com.dipendughosh.servicedemo;

import android.app.IntentService;
import android.content.Intent;
import android.support.annotation.Nullable;
import android.widget.Toast;

public class MyService extends IntentService {

    public MyService() {
        super("my_intent_thread");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Toast.makeText(MyService.this, "intent service started", Toast.LENGTH_SHORT).show();
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        Toast.makeText(MyService.this, "intent service destroied", Toast.LENGTH_SHORT).show();
        super.onDestroy();
    }

    @Override
    protected void onHandleIntent(@Nullable Intent intent) {
        synchronized (this) {
            try {
                wait(20000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
