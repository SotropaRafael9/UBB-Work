from django.db import models

# Create your domain models here.

class Bird(models.Model):
    name = models.CharField(max_length=100)
    color = models.CharField(max_length=100)
    speed = models.FloatField()
    nest_id = models.ForeignKey('Nest', on_delete=models.CASCADE, null=True)

    def __str__(self):
        return self.name + ' - ' + self.color + ' - ' + str(self.speed)
    

class Nest(models.Model):
    location = models.CharField(max_length=100)
    capacity = models.IntegerField()

    def __str__(self):
        return self.location + ' - ' + self.bird.name 


    

