package com.pmobile.prova1.services;

import java.util.HashMap;
import java.util.Map;

public class Login {
    private Map<String, String> usuarios;

    public Login() {
        this.usuarios = new HashMap<>();
        this.usuarios.put("professor", "fatec");
    }

    public Boolean validarLogin(String usuario, String senha) {
        if (!this.usuarios.containsKey(usuario)) {
            return false;
        }
        return this.usuarios.get(usuario).equals(senha);
    }
}
