use context starter2024
data Pessoas:
  |ninguem 
  |pessoa(
      nome :: String,
      ano :: Number,
      tipo-sang :: String,
      pai :: Pessoas,
      mae :: Pessoas
      filhos :: List<Pessoas>
      )
end

CARLOS = pessoa("Carlos", 1926, "A",
  ninguem, ninguem, empty)

BETINA = pessoa("Betina", 1927, "B",
  ninguem, ninguem, empty)

EVA = pessoa("Eva", 1960, "O",
  CARLOS, BETINA, empty)

FRED = pessoa("Fred", 1958, "A",
  ninguem, ninguem, empty)

GUSTAVO = pessoa("Gustavo", 1988, "A",
  FRED, EVA, [list: JJJ, JOAO])

fun ancestral-tipo-o(p :: Pessoas) -> Boolean:
  cases (Pessoas)p:
    |ninguem => false
    |pessoa( nome, ano, tipo-sang, pai, mae) => 
      (tipo-sang == "O") or ancestral-tipo-o(pai) or ancestral-tipo-o(mae)
  end
where:
  ancestral-tipo-o(GUSTAVO) is true
  ancestral-tipo-o(FRED) is false
end

fun lista-filhos-tipo-o(lf :: List<Pessoas>)->List<Pessoas>:
  cases(List<Pessoas>)lf:
    |empty => empty
    |link(f,r)=>
      (descendentes-tipo-o(f)) or (lista-filhos-tipo-o(r))
  end
end
      
      
fun descendentes-tipo-o(p :: Pessoas) -> Boolean:
  cases(Pessoas)p:
    |ninguem => false
    |
  

  
  