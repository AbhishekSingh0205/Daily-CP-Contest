const tagForm = document.querySelector('#tag-form');
const tagInput = document.querySelector('#tag-input');
const tagsDiv = document.querySelector('#tags');

const linkForm = document.querySelector('#link-form');
const linkInput = document.querySelector('#link-input');
const tagsInput = document.querySelector('#tags-input');
const linksDiv = document.querySelector('#links');

const allLinks = {};
const allTags = {};

tagForm.addEventListener('submit', (event) => {
  event.preventDefault();
  const tagName = tagInput.value.trim();
  if (tagName) {
    createTag(tagName);
    tagInput.value = '';
  }
});

linkForm.addEventListener('submit', (event) => {
  event.preventDefault();
  const link = linkInput.value.trim();
  const tagNames = tagsInput.value.split(',').map((s) => s.trim()).filter((s) => s);
  if (link && tagNames.length > 0) {
    createLink(link, tagNames);
    linkInput.value = '';
    tagsInput.value = '';
  }
});

function createTag(name) {
  if (!allTags[name]) {
    const tagElement = document.createElement('div');
    tagElement.classList.add('tag-card');
    tagElement.textContent = name;
    const editButton = document.createElement('button');
    editButton.textContent = 'Edit';
    editButton.addEventListener('click', () => {
      const newName = prompt('Enter new name:', name);
      if (newName && newName !== name) {
        editTag(name, newName);
      }
    });
    const deleteButton = document.createElement('button');
    deleteButton.textContent = 'Delete';
    deleteButton.addEventListener('click', () => deleteTag(name));
    tagElement.appendChild(editButton);
    tagElement.appendChild(deleteButton);
    tagsDiv.appendChild(tagElement);
    allTags[name] = { element: tagElement, links: [] };
  }
}

function createLink(link, tagNames) {
  if (!allLinks[link]) {
    const linkElement = document.createElement('div');
    linkElement.classList.add('link-card');
    const linkA = document.createElement('a');
    linkA.textContent = link;
    linkA.href = link;
    linkElement.appendChild(linkA);
    const tagsElement = document.createElement('div');
    tagsElement.classList.add('link-tags');
    tagNames.forEach((tagName) => {
      createTag(tagName);
      const tagElement = document.createElement('span');
      tagElement.classList.add('link-tag');
      tagElement.textContent = tagName;
      allTags[tagName].links.push(link);
      tagsElement.appendChild(tagElement);
    });
   
