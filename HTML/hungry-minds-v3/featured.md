---
layout: page
title: Featured
---

{% assign featured_posts = (site.posts|where:"featured","true") %}
{% for post in featured_posts limit:4 %}
  <a href="{{ site.baseurl }}{{ post.url }}">
    {{ post.title }}
  </a>
{% endfor %}
