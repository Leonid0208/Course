from django.urls import path

from . import views

urlpatterns = [
    path('', views.Showii.as_view())
]