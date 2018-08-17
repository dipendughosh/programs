
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


public class AddUserFragment extends Fragment {

    private EditText Id;
    private EditText Name;
    private EditText Email;
    private Button bnSave;


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View view = inflater.inflate(R.layout.fragment_add_user, container, false);
        bnSave = view.findViewById(R.id.bn_save);
        Id = view.findViewById(R.id.txt_contact_id);
        Name = view.findViewById(R.id.txt_contact_name);
        Email = view.findViewById(R.id.txt_contact_email);

        bnSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int id = Integer.parseInt(Id.getText().toString());
                String name = Name.getText().toString();
                String email = Email.getText().toString();

                User user = new User();
                user.setId(id);
                user.setName(name);
                user.setEmail(email);

                MainActivity.myaAppDatabase.myDao().addUser(user);

                Id.setText("");
                Name.setText("");
                Email.setText("");
                Toast.makeText(getActivity(), "Contact Saved Successfully...", Toast.LENGTH_SHORT).show();
            }
        });
        // Inflate the layout for this fragment
        return view;
    }
}
