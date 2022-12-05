$(function(){
    //Declaração de variáveis
    var vez = 1;
    var vencedor = "";


    //Função para verificar preenchimento de uma fila
    function casasIguais(a, b, c){
        var casaA = $("#casa"+a);
        var casaB = $("#casa"+b);
        var casaC = $("#casa"+c);
        var bgA = $("#casa"+a).css("background-image");
        var bgB = $("#casa"+b).css("background-image");
        var bgC = $("#casa"+c).css("background-image");
        if( (bgA == bgB) && (bgB == bgC) && (bgA != "none" && bgA != "")){
            if(bgA.indexOf("1.png") >= 0)
                vencedor = "1";
            else
                vencedor = "2";
            return true;
        }
        else{
            return false;
        }
    }


    //Função para verificar o fim do jogo
    function verificarFimDeJogo(){
        if( casasIguais(1, 2, 3) || casasIguais(4, 5, 6) || casasIguais(7, 8, 9) ||
            casasIguais(1, 4, 7) || casasIguais(2, 5, 8) || casasIguais(3, 6, 9) ||
            casasIguais(1, 5, 9) || casasIguais(3, 5, 7)
            ){
            $("#resultado").html("<h1>O jogador " + vencedor + " venceu! </h1>");
            $(".casa").off("click");
        }
        if (vencedor == 1){
            axios.get("http://10.128.64.238:80/x") //aqui vai entrar o IP com a rota X
        }else if(vencedor == 2){
            axios.get("http://10.128.64.238:80/o") //aqui vai entrar o IP com a rota O
        }
    }

    //Evento click das casas
    $(".casa").click(function(){
        var bg = $(this).css("background-image");
        document.querySelector("#introducao").innerText == "Ola"
        if(bg == "none" || bg == "")
        {          
            var fig = "url(" + vez.toString() + ".png)";
            $(this).css("background", fig);
            vez = (vez == 1? 2:1); 
            verificarFimDeJogo();
        }
    });
});
    

