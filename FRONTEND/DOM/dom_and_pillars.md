
# 📘 DOM and Its 4 Pillars

The **Document Object Model (DOM)** is a programming interface that represents an HTML document as a tree of objects. It allows JavaScript to read, modify, and interact with a web page dynamically.
(CamelCase)

---

## 🔹 Pillar 1: Selection of an Element by ID

You can select an individual HTML element using its `id` with:

```js
const title = document.getElementById("main-title");
// # is not used here 
```

Example HTML:
```html
<h1 id="main-title">Welcome!</h1>
```

---

## 🔹 Pillar 2: Selection of HTML by Class or Tag

You can also select elements by **class**, **tag**, or **CSS selectors**:

```js
const boxes = document.getElementsByClassName("box"); 
// HTMLCollection
// . is used not here 
const paragraphs = document.getElementsByTagName("p"); 
// HTMLCollection
const firstBox = document.querySelector(".box");       
// Single element selected 
const allBoxes = document.querySelectorAll(".box");
// All element selected in the form nodeList
// box[0]. -> select 1st element of nodeList
// box[1]. -> select 2nd element of nodeList
h1.innerHTML="<h1>Changed through DOM/<h1>"
// o/p-> Changed through DOM (in h1)
// To change content of html,parse html tag
h1.textContent="<h1>Changed through DOM/<h1>"
// o/p-> <h1>Changed through DOM/<h1>
// To change content of html


```

Example HTML:
```html
<div class="box">Box 1</div>
<div class="box">Box 2</div>
```

---

## 🔹 Pillar 3: Changing CSS through DOM

You can directly manipulate styles using the `.style` property:

```js
const box = document.querySelector(".box");
box.style.backgroundColor = "lightblue";
box.style.border = "2px solid black";
box.style.padding = "10px";
```

Example HTML:
```html
<div class="box">Styled Box</div>
```

---

## 🔹 Pillar 4: Event Listeners

Event listeners allow you to run JavaScript when something happens (click, hover, input, etc.):

```js
const btn = document.getElementById("myBtn");

btn.addEventListener("click", () => {
  alert("Button clicked!");
});
```

Example HTML:
```html
<button id="myBtn">Click Me</button>
```

---

## ✅ Summary

| Pillar               | Purpose                            | Method(s) Used                                     |
|----------------------|------------------------------------|----------------------------------------------------|
| 1. Element by ID      | Select single element              | `getElementById()`                                 |
| 2. HTML by Class/Tag  | Select multiple or specific tags   | `getElementsByClassName()`, `querySelector()`      |
| 3. Change CSS         | Modify style of elements           | `element.style.property = "value"`                 |
| 4. Event Listeners    | Respond to user interactions       | `addEventListener("event", callback)`              |
