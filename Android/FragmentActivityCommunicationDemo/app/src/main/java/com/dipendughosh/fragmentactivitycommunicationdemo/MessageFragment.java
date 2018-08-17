package com.dipendughosh.fragmentactivitycommunicationdemo;


import android.app.Activity;
import android.content.Context;
import android.location.OnNmeaMessageListener;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;


/**
 * A simple {@link Fragment} subclass.
 */
public class MessageFragment extends Fragment {

    private EditText editText;
    private Button button;
    OnMessageReadListner messageReadListner;

    public MessageFragment() {
        // Required empty public constructor
    }

    public interface OnMessageReadListner {

        public void onMessageRead(String message);
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);

        Activity activity = (Activity) context;

        try {
            messageReadListner = (OnMessageReadListner) activity;
        }
        catch (ClassCastException e) {
            throw new ClassCastException(activity.toString() + "must override OnMessageReadListner");
        }

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_message, container, false);
        editText = view.findViewById(R.id.text_message);
        button = view.findViewById(R.id.btn);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = editText.getText().toString();
                messageReadListner.onMessageRead(message);
            }
        });
        // Inflate the layout for this fragment
        return view;
    }

}
