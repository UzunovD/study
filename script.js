"use strict";
for (let obj of document.querySelectorAll(".but")) {
    obj.addEventListener("click", checkAnswer);
}

function checkAnswer(event) {
    const target = event.currentTarget;
    const value = target.innerHTML;
    let color;
    let result;
    if (value === "3 people per 1 sheep") {
        color = "green";
        result = "Correct!";
    }
    else {
        color = "red";
        result = "Incorrect!";
    }
    target.style.backgroundColor = color;
    const fragment = `<div>${result}</div>`;
    let insertion = document.querySelectorAll("button")[0];
    insertion.insertAdjacentHTML('beforebegin', fragment);

    function f() {
        for ( let obj of document.querySelectorAll(".but")) {
          obj.removeEventListener("click", checkAnswer);
        }
    }
    f();
}

// !!!!!!!!!!!!!!! вначале пытался зафигачить через форму - но форма - отправка пользовательского ввода на сервак...

// let form = document.forms.part2;
// console.log(form);
// let answer2 = form.elements.answer_form;

const button2 = document.querySelector(".but2");
button2.addEventListener("click", checkAnswer2);

function checkAnswer2(event) {
    const field = button2.previousElementSibling;
    let color;
    const answer = field.value.toLowerCase();
    let result;
    if (answer === "switzerland") {
            color = "green";
            result = "Correct!";
        }
        else {
            color = "red";
            result = "Incorrect!";
        }

    const target = document.querySelector("input");
    target.style.backgroundColor = color;
    const fragment = `<div>${result}</div>`;
    target.insertAdjacentHTML('beforebegin', fragment);
    button2.removeEventListener("click", checkAnswer2);

}
