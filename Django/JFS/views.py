from django.shortcuts import render
from django.views.generic.base import View
from django.http import HttpResponse
from .models import Offer


class Showii(View):

    def get(self, requests):
        vacancy = Offer.objects.all()
        return render(requests, 'index.html', {'listik':vacancy})
