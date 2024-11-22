package br.edu.fatec.controller;

import br.edu.fatec.model.Produto;
import br.edu.fatec.repository.ProdutoRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Example;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping(path = "/produtos")
public class ProdutoController {
    @Autowired
    private ProdutoRepository produtoRepository;

    @GetMapping(path = "")
    public ResponseEntity<List<Produto>> get(
            @RequestParam(required = false) String descricao,
            @RequestParam(required = false) String marca,
            @RequestParam(required = false) Integer estoque
    ) {
        Produto produto = new Produto();
        if (descricao != null) {
            produto.setDescricao(descricao);
        }
        if (marca != null) {
            produto.setMarca(marca);
        }
        if (estoque != null) {
            produto.setEstoque(estoque);
        }
        List<Produto> lista = this.produtoRepository.findAll(Example.of(produto));
        return ResponseEntity.ok(lista);
    }

    @PostMapping(path = "")
    public ResponseEntity<Produto> post(@RequestBody Produto produto) {
        Produto entity;
        try {
            if (produto.getEstoque() == null || produto.getValor() == null) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).build();
            }
            produto.setTotal(produto.getEstoque() * produto.getValor());
            entity = this.produtoRepository.save(produto);
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).build();
        }
        return ResponseEntity.status(HttpStatus.CREATED).body(entity);
    }

    @PutMapping(path = "/{id}")
    public ResponseEntity<Produto> update(@PathVariable String id, @RequestBody Produto produto) {
        Produto entity;
        try {
            Integer produtoId = Integer.valueOf(id);
            if (produto.getTotal() != null && (produto.getEstoque() == null || produto.getValor() == null)) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).build();
            }
            produto.setId(produtoId);
            produto.setTotal(produto.getEstoque() * produto.getValor());
            entity = this.produtoRepository.save(produto);
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).build();
        }
        return ResponseEntity.status(HttpStatus.CREATED).body(entity);
    }

    @DeleteMapping(path = "/{id}")
    public ResponseEntity delete(@PathVariable String id) {
        try {
            Integer produtoId = Integer.valueOf(id);
            if (!this.produtoRepository.existsById(produtoId)) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).build();
            }
            this.produtoRepository.deleteById(produtoId);
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).build();
        }
        return ResponseEntity.status(HttpStatus.NO_CONTENT).build();
    }
}
