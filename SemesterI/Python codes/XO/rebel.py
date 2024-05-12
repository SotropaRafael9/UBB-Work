class Song:
    def __init__(self, title, beats, drops):
        self.title = title
        self.beats = beats
        self.drops = drops
    def total_intensity(self):
        return sum(drop.intensity for drop in self.drops)
    
def sort(songs):
    for i in range(len(songs)):
        for j in range(i, len(songs)):
            if songs[i].total_intensity() < songs[j].total_intensity():
                songs[i], songs[j] = songs[j], songs[i]
    return songs

class Beat:
    def __init__(self, intensity):
        self.intensity = intensity

class Drop:
    def __init__(self, intensity):
        self.intensity = intensity

songs = [
    Song('Castle Of glass', [Beat(5), Beat(4), Beat(5)], [Drop(3), Drop(3), Drop(4)]),
    Song('Nothing else matters', [Beat(5), Beat(5), Beat(5)], [Drop(4), Drop(4), Drop(4)]),
    Song('Rockstar', [Beat(5), Beat(4), Beat(5)], [Drop(3), Drop(3), Drop(4)]),
    Song('In the end', [Beat(5), Beat(5), Beat(5)], [Drop(4), Drop(4), Drop(4)]),
    Song('Numb', [Beat(5), Beat(4), Beat(5)], [Drop(3), Drop(3), Drop(4)]),
    Song('Faded', [Beat(5), Beat(5), Beat(5)], [Drop(4), Drop(4), Drop(4)])
]

sorted_songs = sort(songs)
print("top 3 songs are:")
for song in sorted_songs[:3]:
    print(song.title)