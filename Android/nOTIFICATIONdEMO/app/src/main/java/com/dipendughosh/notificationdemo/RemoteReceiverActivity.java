package com.dipendughosh.notificationdemo;

import android.app.NotificationManager;
import android.support.v4.app.RemoteInput;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class RemoteReceiverActivity extends AppCompatActivity {

    private TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_remote_receiver);

        textView = findViewById(R.id.txtDisplay);

        Bundle remoteReply = RemoteInput.getResultsFromIntent(getIntent());

        if (remoteReply != null) {
            String message = remoteReply.getCharSequence(MainActivity.TXT_REPLY).toString();
            textView.setText(message);
        }

        NotificationManager notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        notificationManager.cancel(MainActivity.NOTIFICATION_ID);
    }
}
