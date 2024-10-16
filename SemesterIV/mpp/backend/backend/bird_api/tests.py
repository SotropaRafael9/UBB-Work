from collections.abc import Callable
from django.test import TestCase
from .models import Bird, Nest


class BirdTestCase(TestCase):
    def setUp(self):
        Bird.objects.create(name="Eagle", color="Brown", speed=2.5)
        Bird.objects.create(name="Sparrow", color="Gray", speed=0.5)

    def test_add_bird(self):
        Bird.objects.create(name="Hawk", color="Black", speed=3.0)
        hawk = Bird.objects.get(name="Hawk")
        self.assertEqual(hawk.name, "Hawk")
        self.assertEqual(hawk.color, "Black")
        self.assertAlmostEqual(hawk.speed, 3.0)

    def test_delete_bird(self):
        sparrow = Bird.objects.get(name="Sparrow")
        sparrow.delete()
        with self.assertRaises(Bird.DoesNotExist):
            Bird.objects.get(name="Sparrow")

    def test_update_bird(self):
        eagle = Bird.objects.get(name="Eagle")
        eagle.color = "White"
        eagle.save()
        updated_eagle = Bird.objects.get(name="Eagle")
        self.assertEqual(updated_eagle.color, "White")

    def test_sort_bird(self):
        Bird.objects.create(name="Hawk", color="Black", speed=3.0)
        Bird.objects.create(name="Pigeon", color="White", speed=1.0)
        birds = Bird.objects.all().order_by("color")
        self.assertEqual(birds[0].color, "Black")
        self.assertEqual(birds[1].color, "Brown")
        self.assertEqual(birds[2].color, "Gray")
        self.assertEqual(birds[3].color, "White")

    def test_paginated_bird(self):
        Bird.objects.create(name="Hawk", color="Black", speed=3.0)
        Bird.objects.create(name="Pigeon", color="White", speed=1.0)
        birds = Bird.objects.all()
        page = 1
        page_size = 2
        paginated_birds = birds[(page-1)*page_size:page*page_size]
        self.assertEqual(len(paginated_birds), 2)
        self.assertEqual(paginated_birds[0].name, "Eagle")
        self.assertEqual(paginated_birds[1].name, "Sparrow")

    def test_filter_bird(self):
        Bird.objects.create(name="Hawk", color="Black", speed=3.0)
        Bird.objects.create(name="Pigeon", color="White", speed=1.0)
        birds = Bird.objects.filter(color="Black")
        self.assertEqual(len(birds), 1)
        self.assertEqual(birds[0].name, "Hawk")
        self.assertEqual(birds[0].color, "Black")
        self.assertEqual(birds[0].speed, 3.0)

class NestTestCase(TestCase):
    def setUp(self) -> None:
        Nest.objects.create(location="Tree", capacity=5)
        Nest.objects.create(location="Bush", capacity=3)

    def test_add_nest(self):
        Nest.objects.create(location="Ground", capacity=10)
        ground = Nest.objects.get(location="Ground")
        self.assertEqual(ground.location, "Ground")
        self.assertEqual(ground.capacity, 10)

    def test_delete_nest(self):
        bush = Nest.objects.get(location="Bush")
        bush.delete()
        with self.assertRaises(Nest.DoesNotExist):
            Nest.objects.get(location="Bush")

    def test_update_nest(self):
        tree = Nest.objects.get(location="Tree")
        tree.capacity = 10
        tree.save()
        updated_tree = Nest.objects.get(location="Tree")
        self.assertEqual(updated_tree.capacity, 10)

    