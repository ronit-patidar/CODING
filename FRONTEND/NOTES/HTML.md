
# 📚 HTML Revision Sheet

A quick reference guide for HTML covering all important topics needed for web development and placements.

---

## ✅ Basic HTML Structure

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Page Title</title>
</head>
<body>
  <!-- Content goes here -->
</body>
</html>
```

---

## 🏷️ Common HTML Tags

| Tag         | Description                          |
|-------------|--------------------------------------|
| `<h1>`–`<h6>` | Headings (1 = largest)              |
| `<p>`       | Paragraph                            |
| `<br>`      | Line break (self-closing)            |
| `<hr>`      | Horizontal rule                      |
| `<a href="">`| Anchor (link)                        |
| `<img src="">`| Image                              |
| `<strong>` / `<b>` | Bold text                    |
| `<em>` / `<i>` | Italic text                      |
| `<ul>` / `<ol>` / `<li>` | Lists                 |
| `<div>`     | Generic container                    |
| `<span>`    | Inline container                     |

---

## 📷 Image Tag

```html
<img src="image.jpg" alt="Description" width="200">
```

---

## 🔗 Anchor Tag

```html
<a href="https://example.com" target="_blank">Visit Site</a>
```

---

## 🧱 Forms

```html
<form action="/submit" method="POST">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name">

  <input type="submit" value="Submit">
</form>
```

**Form Elements:**
- `<input type="text|email|password|radio|checkbox|submit">`
- `<textarea>`, `<select>`, `<option>`

---

## 🧠 Semantic Tags

| Tag           | Use Case                        |
|----------------|---------------------------------|
| `<header>`     | Top of the page                 |
| `<nav>`        | Navigation links                |
| `<main>`       | Main content                    |
| `<section>`    | Section of content              |
| `<article>`    | Independent content             |
| `<aside>`      | Side content                    |
| `<footer>`     | Bottom of the page              |



---

## 🎨 Inline Styles & Attributes

```html
<p style="color: red; font-size: 18px;">Styled Text</p>
<img src="pic.jpg" alt="Pic" width="100" height="100">
```

---


---

## 🧾 Comments

```html
<!-- This is a comment -->
```

---

## ⌨️ Keyboard Shortcuts (VS Code)

| Action              | Shortcut         |
|---------------------|------------------|
| Emmet Abbreviation  | `!` + Tab        |
| Wrap with Tag       | `Shift + Alt + W`|
| Duplicate Line      | `Shift + Alt + Down` |

---

## 🌐 Doctype Declaration

```html
<!DOCTYPE html> <!-- Defines HTML5 -->
```

---

## 📌 Best Practices

- Use semantic tags for better SEO & accessibility.
- Always close your tags.
- Add `alt` attributes for all images.
- Use lowercase for HTML tags & attributes.
- Keep indentation consistent.

---

## 🧪 Sample Project Structure

```
project-folder/
│
├── index.html
├── style.css
└── script.js
```

---

## 🛠️ HTML5 APIs (Just Basics)

| API            | Description                     |
|----------------|---------------------------------|
| Geolocation    | Get user’s location              |
| Drag and Drop  | Drag elements                    |
| LocalStorage   | Store data in browser            |
| Canvas         | Draw graphics                    |

---

## 📎 Resources

- [MDN Web Docs](https://developer.mozilla.org/en-US/docs/Web/HTML)
- [W3Schools](https://www.w3schools.com/html/)
- [freeCodeCamp](https://www.freecodecamp.org/learn/)

---

**Happy Coding! 🚀**
