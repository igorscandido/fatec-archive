package br.edu.fatec.controller;

import br.edu.fatec.model.Cliente;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping(path = "/clientes")
public class ClienteController {
	private List<Cliente> clientes = new ArrayList<Cliente>();
	
	@PostMapping
	public ResponseEntity<?> insert(@RequestBody Cliente cliente) {
		for (Cliente listClient : this.clientes) {
			if (listClient.getCpf().equals(cliente.getCpf())) {
				return ResponseEntity.status(HttpStatus.CONFLICT).build();
			}
		}
		
		cliente.setCodigo((int) (Math.random() * 1000));
		this.clientes.add(cliente);
		return ResponseEntity.status(HttpStatus.CREATED).body(cliente);
	}
	
	@GetMapping
	public ResponseEntity<?> get(
	        @RequestParam(required = false) String nome, 
	        @RequestParam(required = false) String cidade,
	        @RequestParam(required = false) String instituicao,
	        @RequestParam(required = false) String curso) {
	    List<Cliente> responseClientes = this.clientes;
	    if (nome != null && !nome.isEmpty()) {
	        responseClientes = responseClientes.stream()
	                .filter(cliente -> cliente.getNome().contains(nome))
	                .collect(Collectors.toList());
	    }
	    if (cidade != null && !cidade.isEmpty()) {
	        responseClientes = responseClientes.stream()
	                .filter(cliente -> cliente.getEndereco().getCidade().equals(cidade))
	                .collect(Collectors.toList());
	    }
	    if (instituicao != null && !instituicao.isEmpty()) {
	        responseClientes = responseClientes.stream()
	                .filter(cliente -> cliente.getCurso().getInstituicao().equals(instituicao))
	                .collect(Collectors.toList());
	    }
	    if (curso != null && !curso.isEmpty()) {
	        responseClientes = responseClientes.stream()
	                .filter(cliente -> cliente.getCurso().getCurso().equals(curso))
	                .collect(Collectors.toList());
	    }

	    return ResponseEntity.ok(responseClientes);
	}
	
	@PutMapping(path = "/{codigo}")
	public ResponseEntity<?> alter(@PathVariable Integer codigo, @RequestBody Cliente cliente) {
		for (Cliente listClient : this.clientes) {
			if (listClient.getCodigo().equals(codigo)) {
				this.clientes.remove(listClient);
				cliente.setCodigo(codigo);
				this.clientes.add(cliente);
				return ResponseEntity.status(HttpStatus.NO_CONTENT).build();
			}
		}
		
		return ResponseEntity.status(HttpStatus.NOT_FOUND).build();
	}
	
	@DeleteMapping(path = "/{codigo}")
	public ResponseEntity<?> delete(@PathVariable Integer codigo) {
		for (Cliente listClient : this.clientes) {
			if (listClient.getCodigo().equals(codigo)) {
				this.clientes.remove(listClient);
				return ResponseEntity.status(HttpStatus.NO_CONTENT).build();
			}
		}
		
		return ResponseEntity.status(HttpStatus.NOT_FOUND).build();
	}

}
