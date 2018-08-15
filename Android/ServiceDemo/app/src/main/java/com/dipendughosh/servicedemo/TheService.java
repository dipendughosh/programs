package com.dipendughosh.servicedemo;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.support.annotation.Nullable;
import android.widget.Toast;

public class TheService extends Service {

    final class TheThread implements  Runnable {
        int serviceID;

        public TheThread(int serviceID) {
            this.serviceID = serviceID;
        }

        @Override
        public void run() {
            synchronized (this) {
                try {
                    wait(20000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                stopSelf(serviceID);
            }
        }
    }

    @Override
    public void onCreate() {
        super.onCreate();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Toast.makeText(TheService.this, "service started", Toast.LENGTH_SHORT).show();
        Thread thread = new Thread(new TheThread(startId));
        thread.start();
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        Toast.makeText(TheService.this, "service destroied", Toast.LENGTH_SHORT).show();
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}
