package com.pmobile.prova1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.pmobile.prova1.services.Login;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void clickEntrar(View view) {
        EditText edtUsuario = findViewById(R.id.edtUsuario);
        EditText edtSenha = findViewById(R.id.edtSenha);
        String usuario = edtUsuario.getText().toString();
        String senha = edtSenha.getText().toString();

        Login loginService = new Login();
        if (loginService.validarLogin(usuario, senha)) {
            startActivity(new Intent(this, Boletim.class));
        } else {
            Toast.makeText(this, "Usuario e/ou senha invalidos",
                    Toast.LENGTH_SHORT).show();
        }

    }
}