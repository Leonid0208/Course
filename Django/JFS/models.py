from django.db import models


class Skill(models.Model):
    name = models.CharField(max_length=100)
    url = models.SlugField(max_length=200, unique=True)

    def __str__(self):
        return self.name


class Offer(models.Model):
    h1 = models.CharField('Заголовок', max_length=300)
    location = models.CharField('Расположение офиса', max_length=100)
    organization = models.CharField('Название компании', max_length=150)
    salary = models.CharField('ЗП', max_length=100, default='Договорная')
    description = models.TextField('Описание')
    url = models.SlugField(max_length=200, unique=True)

    def __str__(self):
        return self.h1

