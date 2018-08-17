package com.dipendughosh.roomdemo;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


public class UpdateUserFragment extends Fragment {

    private EditText Update_Id;
    private EditText Update_Name;
    private EditText Update_Email;
    private Button Update_bnUpdate;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_update_user, container, false);
        Update_bnUpdate =view.findViewById(R.id.bn_update);
        Update_Id = view.findViewById(R.id.txt_update_id);
        Update_Name = view.findViewById(R.id.txt_update_name);
        Update_Email = view.findViewById(R.id.txt_update_email);
        Update_bnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int id = Integer.parseInt(Update_Id.getText().toString());
                String name = Update_Name.getText().toString();
                String email = Update_Email.getText().toString();

                User user = new User();
                user.setId(id);
                user.setName(name);
                user.setEmail(email);

                MainActivity.myaAppDatabase.myDao().updateUser(user);

                Update_Id.setText("");
                Update_Name.setText("");
                Update_Email.setText("");
                Toast.makeText(getActivity(), "Contact Updated Successfully...", Toast.LENGTH_SHORT).show();
            }
        });
        // Inflate the layout for this fragment
        return view;
    }
}
