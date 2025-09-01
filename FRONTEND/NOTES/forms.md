
# 📋 Most Frequently Used HTML Form Elements – Quick Reference

This sheet includes the most common and frequently used HTML form elements, with syntax and key attributes.

---
# Go to your project folder
cd path/to/your/project

# Add GitHub remote
git remote add origin https://github.com/your-username/your-repo-name.git

# Check if remote added correctly
git remote -v

# Add and commit any changes (if needed)
git add .
git commit -m "Your commit message"

# Push to GitHub
git push -u origin master  # or main

## 🔤 1. Text Input

```html
<input type="text" name="username" placeholder="Enter your name" required>
```

### Attributes:
- `type="text"`
- `placeholder`
- `name`
- `required`
- `maxlength`, `minlength`
- `value`

---

## 📧 2. Email Input

```html
<input type="email" name="email" placeholder="Enter your email" required>
```

### Validates proper email format automatically.

---

## 🔒 3. Password Input

```html
<input type="password" name="password" required minlength="6">
```

### Masks characters for privacy.

---

## 📅 4. Date Picker

```html
<input type="date" name="dob">
```

### Attributes:
- `min`, `max`
- `value`

---

## 🔘 5. Radio Buttons

```html
<input type="radio" name="gender" value="male"> Male
<input type="radio" name="gender" value="female"> Female
```

### Grouped by the same `name`.

---

## ☑️ 6. Checkboxes

```html
<input type="checkbox" name="subscribe" checked> Subscribe to newsletter
```

### Used for multiple selections.

---

## 🔽 7. Dropdown Select

```html
<select name="country">
  <option value="in">India</option>
  <option value="us">USA</option>
</select>
```

### Attributes:
- `multiple`
- `disabled`
- `selected` on `<option>`

---

## 📝 8. Textarea

```html
<textarea name="message" rows="4" cols="40" placeholder="Type your message..."></textarea>
```

### Attributes:
- `rows`, `cols`
- `maxlength`, `placeholder`, `required`

---

## 📎 9. File Upload

```html
<input type="file" name="resume">
```

### Attributes:
- `accept=".pdf,.doc"`
- `multiple`

---

## 🎚️ 10. Range Slider

```html
<input type="range" name="volume" min="0" max="100" value="50">
```

---

## 🔢 11. Number Input

```html
<input type="number" name="age" min="1" max="100">
```

---

## 🎯 12. Submit Button

```html
<input type="submit" value="Submit">
```

or

```html
<button type="submit">Submit</button>
```

---

## 🧼 13. Reset Button

```html
<input type="reset" value="Reset Form">
```

---

## 🖱️ 14. Button

```html
<button type="button" onclick="alert('Clicked')">Click Me</button>
```

---

## 📎 Bonus: Form Skeleton Example

```html
<form action="/submit" method="POST">
  <input type="text" name="username" placeholder="Name">
  <input type="email" name="email" placeholder="Email">
  <input type="password" name="password" placeholder="Password">
  <input type="submit" value="Register">
</form>
```

---

**Tip:** Always include `name`, `required`, and `placeholder` for user-friendly and functional forms.

---

**Happy Coding! 💡**
